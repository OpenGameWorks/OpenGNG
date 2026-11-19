# OpenGNG

"GNG" stands for *Ghosts n' Goblins*, a series which the Maximo games are under.

OpenGNG's first project is to attempt decompilation of the sequel to "Maximo: Ghosts to Glory", being "Maximo: The Army of Zin", as it has complete debug symbols inside it, for the PS2.

You can take liberties and tooling code from xsyetopz/GodHand repository, including their .claude/agents/ definitions, and adjust to this repo. Same principle and live feed on unobscured port: match byte-for-byte using exact tooling and language standard they did. it is a 100% byte-match decompilation for the PS2, including following the exact code structure that the debug symbols give.

SLUS-20722.iso is in this repo. Dissect it if not already dissected. At the end of the day, users should only provide the .iso/.chd (that gets converted to .iso) of this exact game, because it needs to take assets from it. Everything else is handled.
