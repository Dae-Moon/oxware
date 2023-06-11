<div align="center">

<img src="https://i.imgur.com/rMxVH3j.png" width="27%" height="27%"></img>


Welcome to **oxWARE**! A free Counter-Strike 1.6 cheat built with love and passion, featuring over **46,000 lines of C++ code in more than 233 source files!**

This cheat is still in <b>alpha stage</b> of development!<br>
I will be contributing to it in the near future as much as possible, adding new features et cetera.<br>
So stay tuned! 😉<br><br>

Please, before proceeding, **read this README**!

</div>

---

## Table of contents

- [Special thanks to](#special-thanks-to)
- [Usage](#usage)
- [Multi-platform support](#multi-platform-support)
- [Support on non-steam and older versions of the game](#support-on-non-steam-and-older-versions-of-the-game)
- [Uninstalling](#uninstalling)
- [Anti-cheats](#anti-cheats)
	- [VAC](#vac)
- [Building](#building)
- [Features](#features)
- [To be done](#to-be-done)
- [Changelog](#changelog)

## Special thanks to

- [phnt](https://github.com/processhacker/phnt) for providing great collection of native Windows kernel API, definitions, and more.
- [Microsoft Detours](https://github.com/microsoft/Detours) for their Detouring open-source library.
- [GLFW](https://github.com/glfw/glfw) for their robust open-source OpenGL library.
- [imgui](https://github.com/ocornut/imgui) for literally the best light-weight GUI out there.
- [json](https://github.com/nlohmann/json) for the very mature json library.
- [soil](https://github.com/littlstar/soil) for its functionality over simplifying the process of loading opengl images.
- Voooolve for making an excelent decision of building their linux build of the game with debug symbols, making it easier to make cheats for their game 😉 ... Thanks Valve.
- Anyone who plays using this cheat client or contributes to it somehow. 😎

## Usage

The cheat is composed out of two parts: **the loader (oxware.exe)** and **the cheat module (cheater.dll)**. By using the loader you can inject the cheat module to the game. After injecting the cheat, you can use `INSERT key to open up the menu`. 

Both the cheat and loader have developer consoles built inside of them that you can access at any time. (inside the cheat it is the '~' key, below the escape key)

## Cheat menu in-game

![The cheat](https://i.imgur.com/nek7Sst.png)

## The loader

![The loader](https://i.imgur.com/j0hOePU.png)

# Support on other operating systems

This cheat is currently only available on `Windows 10 and newer`.

While making this cheat cross-platform (e.g. porting to Linux or OSX) isn't completely impossible, it would take a lot of effort, because from the beginning I designed this cheat mainly for Windows. But that being said, it isn't impossible to port.

# Support on non-steam and older versions of the game

This cheat currently supports following builds:

- `8684 steam version`
- `4554 non-steam version`
- xguard, gsclient or other custom implementations **aren't supported**.

## Uninstalling

Inside the cheat folder you can find a script called `uninstall.bat` that will uninstall all of the things that the cheat currently store on your computer. This **ins't a virus!** So feel free using it. After you run the script, you can delete the cheat folder.

However, if you still don't believe me that I have put a virus to a cheat with public source code 😁, you can still uninstall all of the things manually 🤔 (actually, as of now - June 2023, there are only **two** things that the cheat stores on your machine).

- Delete the program (oxware.exe with other DLLs)
- Go to your appdata folder and then into folder "**Roaming**" (if you don't know how to get there, search the internet on how to get there). Then find folder called **oxware** and delete it.
- Then delete the registry data that the cheat left behind:
	- Go to registry editor (again, if you don't know how, google it)
	- And go to "**HKEY_CURRENT_USER -> SOFTWARE -> oxware**" and delete the entry.

## Anti-cheats

The cheat wasn't tested on any anticheats so far. It may or may not be detected. **USE AT YOUR OWN RISK**!

### VAC

As far as I know, the CS 1.6 VAC is not so smart, so **YOU SHOULD NOT GET VAC BANNED BY USING THIS**, but having said that, **USE STILL AT YOUR OWN RISK!**

### Wargods

There have been reports with WG already detecting this cheat. In order to not get detected by WG scan even when you "removed" the cheat, you need to run the uninstall script. More on that in here: [uninstalling](#uninstalling).

## Building

This cheat is currently only available to be built inside the **Visual Studio** environment, any other building software haven't been tested or added yet.

In order to build, you will need **Visual Studio 2022** with **C++20 support**, and **v143 toolset**.

There are three main build configurations:

- **debug**: for debugging and development.

- **release**: for testing retail-like circumstances without the debug overhead.

- **retail**: for final deployment only.

In order to fully build everything, all you need to do is just hit **ctrl + shift + b** or navigate to the solution and select **Rebuild Solution**. New **build\\** directory will be created and all of the executables will be placed here.

**Also see building.md in the root directory of this repo!**

## Features

- Removals
	- screen shake
	- MOTD
	- Viewmodel
	- Sniper scopes
	- Players
- HUD removals
	- weapon, crosshair, money, etc...
- Viewmodel offset
- Smoke visuals, see [this video](https://youtu.be/PL2f-weiF84). 🚬
- Flashbang fade modifier
- Built-in console with custom commands 🖥
- FOV changer
- Server liar (sending false cvar values to the server)
- Skeletal chams 💀
- Playermodel head hitbox rendering, see [this image](https://i.imgur.com/bYzp8KD.png). 🟩
- Server command filter (svc_stufftext filter)
- Ability to view "real" hit-able playermodel and its head hitbox. See [this image](https://i.imgur.com/weWGM5C.png) and [this youtube video](https://youtu.be/xMd9m3McNvo).
- ESP
	- Player
	- Entities
	- Sound
	- Custom box types
- Model chams
	- Viewmodel
	- Players (T and CT)
	- Rainbow colors
	- Flat/shaded
	- Disabled playermodel animations
- Thirdperson
- Bypassing game constrains
	- Re-enabling noclip (normally disabled in CS 1.6)
	- Custom render distance
	- Re-enabling some renderer cvars (normally unable to set in SP & MP)
	- Allow SP-only cvars also in MP
- Frame skipping/simulated framerate
- Vanilla-like crosshair changer ➕
- Custom HUD rendering 🌈 such as:
	- Displaying currently held weapon 🔫
	- Displaying current velocity 
- Default viewmodel enforcement
- Movement
	- Air stuck, see [this video](https://youtu.be/9snddT03M34).
	- Legit/Rage bhop hack 🐇
	- GS hack.
	- EB hack.
	- Strafe hack.
	- Strafe helper.
	- Fast run & fast walk.
	- Auto JOF.
- Fancy custom cl_showfps rendering
- Rechecker bypass, see [this video](https://youtu.be/Razs0s7sgno).
- Instantaneous cheat unload (either via loader or cheat menu)
- Injection using manual mapping 🗺
- Custom UI (modified version of imgui)
- Key binding
- Configuration files ⚙

## To be done

All of the things that are left to be done are inside our [trello board](https://trello.com/b/mmVAu6Gt/oxware).

## Changelog

See [changelog.md](https://github.com/oxiKKK/oxware/blob/main/changelog.md) for more information.
