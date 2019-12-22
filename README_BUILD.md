### Dependencies

This program has five main dependencies

* Qt 5 (https://www.qt.io/download)
* BASS (http://www.un4seen.com/bass.html)
* BASS Opus Plugin (http://www.un4seen.com/bass.html#addons)
* Discord Rich Presence (https://github.com/discordapp/discord-rpc/releases)
* Qt Apng Plugin (https://github.com/Skycoder42/QtApng/releases)

### How to build dynamically (the easy way)

#### General preparation

What you want to do is first download the version of Qt which has an available Qt Apng build.
After going through the OS-specific steps below, compiling in Qt creator should work.

#### Windows

If you're on Windows, you need to go find all the dependencies (see above) and put them in the lib/ folder.
After compilation, you can use `windeployqt` to automatically find and copy over all the relevant shared libraries.

#### MacOS

If you're on MacOS, you can simply go to terminal and run ./scripts/configure_macos.sh
This will automatically fetch all the required dependencies. Additionally, if you need to create a standalone release, just run ./scripts/release_macos.sh
This will make the .app bundle in bin/ able to execute as a standalone.

#### Ubuntu

If you're on Ubuntu, just go to terminal and run ./scripts/configure_ubuntu.sh
This should fetch all the required dependencies automatically.  

#### Other Linux

With some tweaks to the ubuntu script, it shouldn't be a big hassle to compile it on a modern linux. Look in the script and see what you may have to modify.
