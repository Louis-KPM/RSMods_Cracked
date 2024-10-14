# RSMods, but will work on cracked versions of RS2014 - Remastered.


* Below is the original description for the great repo by reknowned anti-piracy advocate Lovrom8

## Features:

* **Extended Range Mode**
  * Rocksmith by default doesn't officialy support 7 (or more) string guitars or 5 string bass, even though a few low-tuned songs have been released as official DLC. 
    Hence with the power of DX9, GDI+ and some smart reverse engineering, when it detects that a song is in a tuning lower than the set threshold, the color scheme    will change accordingly. What that means is that no more will your brain be confused because the lowest string is colored red (usually indicating the low E string), while you actually need to play the low B! So effectively all the strings will be shifted one place down.
   * **Options**
   1. ZZ's color set - this mode will replicate the default color of high B string (the teal / green used in colorblind mode) and make it match the color of the low B string (7-th string) - [See the ER mode in action](https://www.youtube.com/watch?v=FPjFwt-Dpdo). Note this video is from an older mod method, but the way it displays in game is the same, the enabling of it is now just all done automatically based on tuning, rather than enabling "Colorblind" mode.
   2. Custom color set - defined by you as the colorblind color set in the settings, it will be used only in extended range mode songs, while regular songs will use the normal colors
   ** Known bugs: Some highlights for accented open strings or HO / PO notations, flicker between the default colors and the modified ER mode colors.
                  The string pegs shown in the tuner are not changed correctly. The colors change when the song starts, not in the tuner, meaning on first ER use, default colors will be shown in the tuner. It also means that if you last played an ER song, then go back to a standard tuned song - the pegs in the tuner will still show in ER colors.
      
* **Custom Song List Titles**
  * Normally those are not customizable in-game and simply listed as SONG LIST 1 to SONG LIST 6. Now you can customize those, making for example, a song list for only B Standard songs, only Excercise songs, etc.
  
* **Add/Decrease Song Volume**
  * In case you are playing a song which is unusually low in volume, or is ear-piercingly loud, by invoking the functions of AudioKinetic audio engine used by the game, you can now modify volume of the music on the fly, without going in to the mixer. 
  
* **Toggle Loft**
  * If you are a streamer, this one may especially come in handy. The background behind the noteway (be it a crowd in the venue or just a plain wall), can now be removed on the fly and replaced with a dark background. It is suggested that you also turn off "Venue Mode" in the game settings as this will help with performance a little as well as make sure you don't have the colored showlights being displayed. The all black background can then be "keyed out" in OBS using a Luma key set for black (luma key works better than chroma key for this), effectively giving you the ability to make the note highway "float" over whatever background you use. To you while playing, or recording game footage locally, it will just appear as an all black background.
  * **Options** - loft can be automatically toggled off as soon as the game is started or only when in a song, or by pressing the hotkey that you define.
  
* **Greenscreen Wall**
  * Similar to Toggle Loft, but only applied to the background wall. This keeps the amps visible and a few of the other UI elements that are removed with Toggle Loft.
  
* **Force ReEnumeration**
  * Normally after adding a new song to your collection, you would have had to either restart the game, or enter the in-game Shop in order for the game to recognize the new songs.
  * **Options**
  1. Automatic - check if any new songs have been added every X seconds (even while a song is playing!)
  2. By going into Enumerate menu - SHOP in the menu has now been replaced with **Enumerate** and conveniently moved to the second place **(GUI only)**
  3. By hotkey - press a hotkey to force the game to enumerate your songs.

* **Removal of certain visual game elements**
  * Again something which may come in handy if you are a streamer (or just prefer your screen to be as uncluttered as possible), you can now remove certain elements from the screen
  * **Options**
  1. Headstock
  2. Skyline (Dynamic Difficulty bars at the top)
  3. Frets
  4. Inlays
  5. Lane Markers
  6. Lyrics
  
* **Rainbow Strings**
  * A fun mod which will continously hue-shift the colors of your strings, making them look like a rainbow! 

* **Custom String Colors**
  * It doesn't all have to be fun and games, so instead of a rainbow, your strings can also be permanently changed in your own color set.

* **Remove song previews**
  * In case you don't like hearing song previews while scrolling through your song list, they can also be disabled.

* **Play audio in background**
  *  Allows you to listen to Rocksmith with the game in the background (alt-tabbed out of the game).
  
* **Linear Riff Repeater**
  * By default, the speed for Riff Repeater is not linear - In standard Rocksmith 2014: 68% speed in Riff Repeater = 50% real speed. With this mod: 68% speed in Riff Repeater = 68% real speed.

* **Enable looping**
  * Allows you to loop sections of songs. This differs from Riff Repeater as we let you pick sections by the amount of time using specialized keybindings to set the loop begining and the loop end.

* **Allow rewinding** 
  * If you mess up a section and want to retry it, you can go back in time for a set amount of seconds. 

* **Custom Non-Stop Play timer**
  * The timer between songs in Non-stop play is 10.9 seconds by default and a lot of people find this timer to be too long. With this mod, you can change the amount of time between each song (down to 2 seconds due to technical limitations).

* **Start RS on secondary monitor**
  * Makes Rocksmith run on your second monitor. Though, make sure to pay attention to the tooltips!

* **Bypass 2+ RealToneCable popups**
  * Allows you to have two Real Tone Cables plugged in while playing singleplayer. Without the mod Rocksmith will stop you from doing this. 

* **Alternative sample rates for sound output**
  * Rocksmith normally needs sample rate of 48kHz, but this mod tells the game to look for a sample rate that you set. Doing this enables you to use headphones/speakers that don't support 48kHz (eg. some Bluetooth headphones). This won't save you from latency, but at least BT headphones will work in the game.

* **Prevent buggy tones**
  * When playing some songs, the tone system may just give up and constantly play the clean tone, no matter the currently enabled tone. To fix this, you normally have to restart your game to get tones working again, but this mod may just help the game recover without restarts.

* **GuitarSpeak**
  * What hides behind this mysterious name is an exciting feature that will let you control the game by playing certain notes on your guitar (fully customizable!). Forget your keyboard and mouse, guitar is where it's at! There is an option to continue to use it while in the tuner - it is off by default as it can cause issues, but if you're happy to continue using it there - hit that button. It is OFF while in a song, tuning menus, and calibration menus by default.

* **Auto enter last used profile**
  * Also know as the Fork-in-the-toaster mod, due to it's simple but effective nature, it is best used in conjunction with the Fast Load mod. The DLL will spam Enter key in order to automatically enter the game. It may cause potential issues if UPLAY servers are unavailable, but in general it makes your life quite a bit easier.

* **Auto tune your Whammy DT**
  * If you own a Digitech Whammy DT and have a device capable of sending MIDI program controls, such as a simple USB-to-MIDI cable or a MIDI output port on an interface, you may find this useful - automatically change the tuning of your guitar to the tuning of the current song without touching the pedal (works even with odd tunings like A443 or similar). Connect your MIDI cable to the MIDI IN port on the Whammy DT, select the MIDI device name in the GUI settings and when on the Pre-Song tuning screen, press the DELETE key to skip tuning and auto activate the drop tuning of the Whammy DT. This assumes your guitar is in E Standard or Drop D when setting the amount of steps the pedal needs to shift, be that pitching up or down. You'll see the lights on the Whammy DT turn on when the mod is activated and it will auto de-activate when on the post song results screen.
 
* **Allow Riff Repeater Speed Above 100** 
  * For whatever reason TTFAF is not fast enough for you, you can now play it in Riff Repeater with speeds over 100%. :)
  * **Options**
 Riff Repeater Speed Increment - we suggest you use 2 as the minimum value here. This means every key press will increase the speed of the track by 2%. This gives you the most flexibility on how fast you want the song to be.
 
* **Screenshot Scores**
  * If keeping track of your improvements is your jam, you may want to use this option which will tell Steam to take a screenshot of your latest playthrough for you. It uses the default key bind in Steam of F12, to take a screenshot when the post song results screen is displayed. 
  
* **Show Current Note**
  * While we still don't have a way of forcing the game to show the pause menu tuner while you are playing, you can enable this budget version to see which note you are currently hitting, so that you can finally hit 100% instead of missing those pesky bends due to _bad note detection_.

* **Show Song Timer**
  * Show a timestamp of your current position in a song. 

* **Override input volume**
  * Now you can turn your guitar or bass up to 11! Rocksmith sets what volume it wants to listen to your cable at, but this mod allows you to bypass that restriction by changing it to whatever you set.

* **Fix Oculus Crash**
  * When you try to open Rocksmith with a Oculus / Meta headset connected to your PC, it typically crashes. This mod tries to avoid the crash by preventing the bad code from running. It may also fix other audio-related crashes when Rocksmith opens.

* **Fast Load** - **GUI Only**
  * If you are running the game from an SSD or especially an NVMe SSD drive, you will enjoy this one - it skips the intro screens and lets you load the game in a matter of seconds. It can be fairly unstable, but in general it should work provided you don't try to use it on a good old mechanical HDD. This is not a DLL mod! This means that removing the DLL will not reverse the change of this mod, as you will need to restore the backup of your cache.psarc or verify your steam files.
  
* **Custom Tunings** - **GUI Only**
  * By default, the game has a fairly limited set of tunings it can recongnize and in cases where it doesn't find in the list, it will just display CUSTOM TUNING. And that isn't of much help, is it? But don't worry, you can now make the game know that a B Standard song is actually B Standard, and not just _Custom Tuning_ :(
  Together with the list we include, you can add your own tunings if you find some which aren't included in the list. This is not a DLL mod! This means that removing the DLL will not reverse the change of this mod, as you will need to restore the backup of your cache.psarc or verify your steam files.
  
* **EXIT GAME in the menu** - **GUI Only**
  * As useful of a device your mouse is, it is not really the most convenient option when you want to exit the game. And until now, you had to use the said mouse to do that, but fret no more. It took only six and a half years, but now you can exit the game by pressing EXIT GAME in the menu (which replaces the UPLAY button, and let's be honest, no-one used that). This is not a DLL mod! This means that removing the DLL will not reverse the change of this mod, as you will need to restore the backup of your cache.psarc or verify your steam files.
  
* **Enable Direct Connect Mode** - **GUI Only** - https://youtu.be/H6nAB5ogfeU
  * This mod enables a hidden input mode that UbiSoft made - but for unknown reasons disabled for release. It is basically Microphone Mode - but with the tone simulations enabled. This is not a DLL mod! This means that removing the DLL will not reverse the change of this mod, as you will need to restore the backup of your cache.psarc or verify your steam files.
  ** Known issues; Some interfaces report the guitar input channel as one that the game isn't expecting, in this case - Direct Connected mode may not work for you particularly well. If you want to test before applying - go into Microphone Mode and see if your interface lets you have some note detection. If it does - then DC mode should work for you once enabled.
  
* **Change Default tones** - **GUI Only**
  * Add your favorite tones to slot number 1 on the tone stick. This is the default tone that is applied when the game loads up. There is a seperate one saved for Lead, Rhythm and Bass. You need to have a tone saved in your profile. It does not need to be assigned to a "tone stick" slot for the GUI to be able to load it and then set it as the new default. This is not a DLL mod! This means that removing the DLL will not reverse the change of this mod, as you will need to restore the backup of your cache.psarc or verify your steam files.

  * Note: While the ability to change the tone of the Emulated Bass is available and can be added easily, we do not want to edit this tone nor do we condone anyone editting this tone. The Emulated Bass tone has a unique characteristic where it's always the same tone either in song, or in the menus. For this reason we believe that the default tone is most likely the best option to pick for the extensive range of songs / genres it can be used in.
  
* **Change Default Guitarcade tones** - **GUI Only**
  * If you just can't stand the sound of the tones in a Guitarcade game, you can change them here. This is not a DLL mod! This means that removing the DLL will not reverse the change of this mod, as you will need to restore the backup of your cache.psarc or verify your steam files.
  
* **Backup Players Profile** - **GUI Only**
  * Everytime the RSMods GUI is opened, it will make a backup of your Rockmsith Player Profiles. This is automated process to help recover from profile corruptions. Profile backups can be found in "Rocksmith2014/Profile_Backups/MM-DD-YYYY_HH-mm-ss".
  
## Installation:
* Use the One-Click-Installer to copy both the DLL and RSMods GUI to the game folder. If it's unable to automatically detect where Rocksmith is installed, it will ask you to point it to the correct folder.
  
## Requirements:
* Latest Steam version of Rocksmith 2014 Remastered on Windows, https://store.steampowered.com/app/221680/Rocksmith_2014_Edition__Remastered/
* MS Visual C++ 2015-2019 Redistributable for the DLL, .NET framework for GUI/One-Click-Installer
* Sorry Mac users, RS on Mac is it's own beast altogether, so we only support the Windows version
  
## Dependencies:
* DirectX 9 SDK, ImGUI, GDI+, Detours, RtMidi - all of which are included in the project folder and should require no additional installations to compile and use the project
* Setup as C++17 / VS2019 projec
