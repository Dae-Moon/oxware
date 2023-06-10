/*
*	OXWARE developed by oxiKKK
*	Copyright (c) 2023
*
*	This program is licensed under the MIT license. By downloading, copying,
*	installing or using this software you agree to this license.
*
*	License Agreement
*
*	Permission is hereby granted, free of charge, to any person obtaining a
*	copy of this software and associated documentation files (the "Software"),
*	to deal in the Software without restriction, including without limitation
*	the rights to use, copy, modify, merge, publish, distribute, sublicense,
*	and/or sell copies of the Software, and to permit persons to whom the
*	Software is furnished to do so, subject to the following conditions:
*
*	The above copyright notice and this permission notice shall be included
*	in all copies or substantial portions of the Software.
*
*	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
*	OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
*	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
*	THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
*	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
*	FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
*	IN THE SOFTWARE.
*/

#include "platform.h"

#include <interface/IUserInput.h>
#include <interface/IInCommands.h>
#include <interface/ICheatInfo.h>

#include "BaseInCommand.h"
#include "Console.h"

#include <string>

//--------------------------------------------------------------

void BaseInCommand::rebind_key_to(int new_vk)
{
	if ((m_vk == new_vk && m_bound_initially) || new_vk == 0)
	{
		return;
	}

	bool found;
	auto& key = g_user_input_i->get_key(new_vk, &found);
	if (!found)
	{
		CConsole::the().info("Failed to rebind InCommand! Invalid key: {}", new_vk);
		return;
	}

	std::string in_id = "in_" + m_command_name;
	std::string out_id = "out_" + m_command_name;

	// remove first, if bound already
	if (key.on_pressed_callback_exists(in_id))
		key.remove_on_pressed_callback(in_id);
	if (key.on_unpressed_callback_exists(in_id))
		key.remove_on_unpressed_callback(out_id);

	// on pressed, once
	key.add_on_pressed_callback(
		in_id,
		[](const std::string& id, UserKey_t* key)
		{
			if (g_cheat_info_i->is_cheat_ui_running() || g_cheat_info_i->is_game_ui_running())
			{
				return;
			}

			auto incmd_id = id.substr(3);
			auto incmd = g_in_commands_i->get_incommand(incmd_id);
			if (incmd)
			{
				fnInCommandCallback pfn = incmd->get_in_fn();
				pfn(incmd);
			}
		});

	// on released, once
	key.add_on_unpressed_callback(
		out_id,
		[](const std::string& id, UserKey_t* key)
		{
			// keep the release key event running even if the UI is up, to deactivate the command.

			auto incmd_id = id.substr(4);
			auto incmd = g_in_commands_i->get_incommand(incmd_id);
			if (incmd)
			{
				fnInCommandCallback pfn = incmd->get_out_fn();
				pfn(incmd);
			}
		});

	std::string key_name_new = g_user_input_i->virtual_key_to_string(new_vk);
	if (!m_bound_initially)
	{
		CConsole::the().info("Bound '{}' to {}.", m_command_name, key_name_new);
	}
	else
	{
		std::string key_name_old = g_user_input_i->virtual_key_to_string(m_vk);
		CConsole::the().info("Rebound '{}' from {} to {}.", m_command_name, key_name_old, key_name_new);
	}

	m_vk = new_vk;
	m_bound_initially = true;
}

//--------------------------------------------------------------

void InCommand::register_cmd()
{
	rebind_key_to(m_vk);
}

//--------------------------------------------------------------

StaticInCommandContainer g_static_incommand_container;

void StaticInCommandContainer::add_incommand(BaseInCommand* in_cmd)
{
	static bool reserved = false;
	if (!reserved)
	{
		reserve_limit();
		reserved = true;
	}

	if (!see_for_overflow(in_cmd))
	{
		return;
	}

	auto [iter, did_insert] = m_incommands.insert(in_cmd);

	assert(did_insert && "Failed to insert a variable because it's already in the list.. duplicated?");
}

void StaticInCommandContainer::reserve_limit()
{
	m_incommands.reserve(k_max_incommands);

	CConsole::the().info("Reserved {} slots for incommands.", k_max_incommands);
}

bool StaticInCommandContainer::see_for_overflow(BaseInCommand* current_incommand)
{
	if (m_incommands.size() >= k_max_incommands)
	{
		CConsole::the().error("InCommand {} couldn't be added, because the limit for current module has already been reached. ({})",
							  current_incommand->get_cmd_name(), k_max_incommands);
		return false;
	}

	return true;
}
