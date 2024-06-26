# Intro

SYSU spring 2024 Software Engineering homework.

# Build

In `./`:

```sh
mkdir build
cd build
```

In `./build/`:

```sh
cmake ..
make
```

# Run

In `./bin/`:

```sh
./fje -f ../test/example.json -i none -s tree
./fje -f ../test/example.json -i poker -s tree
./fje -f ../test/example.json -i none -s rect
./fje -f ../test/example.json -i poker -s rect
```

# Demo

Input:

```
{
    "oranges": {
        "mandarin": {
            "clementine": null,
            "tangerine": "cheap & juicy!"
        }
    },
    "apples": {
        "gala": null,
        "pink lady": null
    }
}
```

Output:

```
├─ oranges                             ┌─ oranges ───────────────────────────────┐
│  └─ mandarin                         │  ├─ mandarin ───────────────────────────┤
│     ├─ clementine                    │  │  ├─ clementine ──────────────────────┤
│     └─ tangerine: cheap & juicy!     │  │  ├─ tangerine: cheap & juicy! ───────┤
└─ apples                              ├─ apples ────────────────────────────────┤
   └─ gala                             └──┴─ gala ───────────────────────────────┘

          (tree)                                 (rectangle)
```

```
├─♢oranges                                 
│  └─♢mandarin                             
│     ├─♤clementine                        
│     └─♤tangerine: cheap & juicy!    
└─♢apples                                  
   └─♤gala                                 

poker-face-icon-family: 
  container icon：♢ 
  leaf icon：♤
```
