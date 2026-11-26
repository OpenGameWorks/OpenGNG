# i386 Wine for the Windows mwccps2 (Metrowerks CodeWarrior PS2) compiler packages.
FROM i386/debian:bookworm-slim
RUN apt-get update && apt-get install -y --no-install-recommends wine wine32 && rm -rf /var/lib/apt/lists/*
ENV WINEDEBUG=-all WINEPREFIX=/wine
RUN wineboot -i >/dev/null 2>&1 || true
