# ENIGMA Engine

*A modular C++23 game‑engine skeleton designed for rapid iteration and long‑term scalability.*

---

## ✨ Current feature set (Phase 1)

* **Cross‑platform window & input** using **GLFW** (Wayland/X11)
* **Centralised logging** via **spdlog** + **fmt** with coloured console and file sink (`logs/boot.log`)
* **Config‑driven compile flags** — `config.txt` controls compile‑time options (e.g. `vsync:true`)

> We’re now entering **Phase 2 – “First Light”**: bringing raw Vulkan online and rendering the first triangle.

---

## 🛠 Build instructions (Arch Linux)

```bash
# Prerequisites – install once
sudo pacman -S --needed clang lld cmake ninja \
                     vulkan-icd-loader vulkan-headers vulkan-validation-layers \
                     glfw-wayland spdlog fmt

# Clone & build
git clone https://github.com/yourname/EnigmaEngine.git
cd EnigmaEngine
cmake -B build -G Ninja
cmake --build build

# Run the sandbox
./build/apps/sandbox/app_sandbox
```

> **Wayland note**  If you use X11 instead of Hyprland/Wayland, install `glfw-x11` or export `GLFW_PLATFORM=x11` before running.

---

## ⚙️ Configuration

`config.txt` lives at the repo root and is parsed at **configure time**. Example:

```
vsync:true
```

* `vsync:true`  ➜  engine compiles with `USE_VSYNC` and the sandbox swaps with V‑Sync on.
* `vsync:false` ➜  engine compiles without V‑Sync (immediate mode).

Edit the file, then re‑run CMake to propagate changes:

```bash
cmake -B build -G Ninja  # reconfigure step picks up new flags
cmake --build build
```

---

## 🗺 Roadmap

| Phase | Milestone                                           | Status         |
| ----- | --------------------------------------------------- | -------------- |
| 1     | Forge & Fire – toolchain, window, logging           | ✅ complete     |
| 2     | First Light – Vulkan instance, swap‑chain, triangle | 🚧 in progress |
| 3     | 1000 Souls – ECS spawning & transform system        | ⏳              |
| 4     | Gravity Wakes – integrate Jolt physics              | ⏳              |
| …     | …                                                   | …              |

---

## 📚 Learning & reference links

* [Khronos Vulkan SDK](https://vulkan.lunarg.com/)
* [GLFW documentation](https://www.glfw.org/docs/latest/)
* [spdlog](https://github.com/gabime/spdlog) & [fmt library](https://fmt.dev/)

---

## License

tbd

