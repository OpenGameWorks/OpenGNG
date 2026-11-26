# OpenGNG

"GNG" stands for *Ghosts n' Goblins*, a series which the Maximo games are under.

OpenGNG's first project is to attempt decompilation of the sequel to "Maximo: Ghosts to Glory", being "Maximo: The Army of Zin", as it has complete debug symbols inside it, for the PS2.

You can take liberties and tooling code from xsyetopz/GodHand repository, including their .claude/agents/ definitions, and adjust to this repo. Same principle and live feed on unobscured port: match byte-for-byte using exact tooling and language standard they did. it is a 100% byte-match decompilation for the PS2, including following the exact code structure that the debug symbols give.

SLUS-20722.iso is in this repo. Dissect it if not already dissected. At the end of the day, users should only provide the .iso/.chd (that gets converted to .iso) of this exact game, because it needs to take assets from it. Everything else is handled.

## Building

Requirements: Python 3.11+, `ninja`, and Docker or Podman (the Metrowerks compiler is a Win32 binary that runs under Wine in an i386 container; on x86 Linux with Wine installed it runs natively). A `.chd` image also needs `chdman` from the MAME tools.

```sh
python3 -m venv .venv && .venv/bin/pip install -r requirements.txt
.venv/bin/python tools/setup.py /path/to/SLUS-20722.iso    # or .chd
```

`tools/setup.py` opens the image read-only and never modifies it. It:

1. converts a `.chd` into `build/disc/`, if one was given
2. extracts the disc into `original/extracted/`
3. stops unless the executable's SHA-1 equals `config/SLUS_207.22.sha1`
4. writes the symbol and relocation tables into `build/info/`
5. configures and runs `ninja`

The first compile downloads the pinned compiler package and builds the Wine image. A good build ends with `build/SLUS_207.22: OK`. After that, `ninja` alone rebuilds.

`tools/progress.py` reports matched game code separately from SCE library code. Functions that stay as original assembly are never counted as matched. SCE library objects are verified only when `ext/sce/` holds the SDK archives; that directory is not shipped.

## Building

Requirements: Python 3.11+, `ninja`, and Docker or Podman. The Metrowerks compiler runs under Wine in the `godhand-eecc:wine` image (built automatically from `tools/docker/wine.Dockerfile`), or under native Wine on x86 Linux. Converting a `.chd` image needs MAME's `chdman`.

```sh
python3 -m venv .venv && .venv/bin/pip install -r requirements.txt
.venv/bin/python tools/setup.py /path/to/SLUS-20722.iso   # or .chd
ninja                                                      # build/SLUS_207.22: OK
```

`tools/setup.py` only reads the disc image. A `.chd` is converted to `build/disc/<name>.iso`. The disc's files go to `original/extracted/`. The script stops unless `SLUS_207.22` matches `config/SLUS_207.22.sha1`, then writes the symbol and relocation tables to `build/info/` and generates `build.ninja`. The first compile downloads the pinned compiler package into `tools/compilers/`.

Progress: `.venv/bin/python tools/progress.py` reports game and SDK separately. A function counts as matched only when the linker placed compiled bytes equal to the original. SDK functions verified against original SCE library objects (`ext/sce/`, supplied separately, never decompiled) count as `library-object`. `tools/live.py` serves the live treemap on port 8722.
