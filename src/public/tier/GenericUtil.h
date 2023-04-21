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

#ifndef GENERICUTIL_H
#define GENERICUTIL_H
#pragma once

class CGenericUtil
{
public:
	DECL_BASIC_CLASS(CGenericUtil);

public:
	HANDLE get_current_process_handle();
	HANDLE get_current_thread_handle();

	// synonym for GetLastError
	DWORD get_last_win_error();

	std::string virtual_key_to_string(int virtual_key);

	void copy_to_clipboard(const std::string& text);

	// invalid address access
	void simulate_crash();

	// returns true if character is a number or a letter.
	bool is_alphabetical_or_number(char c);

	std::string get_filename_from_path(const std::string& path);

	void open_link_inside_browser(const std::string& link);
};

#endif // GENERICUTIL_H