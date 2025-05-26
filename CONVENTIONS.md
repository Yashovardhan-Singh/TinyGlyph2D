# C Project Naming Conventions

This document outlines the naming conventions used throughout the C project for consistent code style and clarity.

---

## Function Naming

| Scope            | Convention                              | Example                                                       |
| ---------------- | --------------------------------------- | ------------------------------------------------------------- |
| Public API       | `camelCase` (with module prefix)        | `entityCreate()`, `audioPlay()`                               |
| Private (Static) | `static camelCase` (with module prefix) | `static entityDrawTilemap()`                                  |
| Internal Helper  | `camelCase` (with `internal_` prefix)   | `internal_entityLoadTexture()`, `internal_audioUpdateState()` |

All function names **must** include a module prefix to avoid name collisions and to clearly indicate ownership.

---

## Struct Naming

| Type             | Convention                          | Example                                   |
| ---------------- | ----------------------------------- | ----------------------------------------- |
| Public/Opaque    | `PascalCase`                        | `Entity`, `Texture`                       |
| Private/Internal | `PascalCase` with `Internal` suffix | `EntityInternal`, `RenderContextInternal` |

---

## Struct Members

| Scope | Convention  | Example                           |
| ----- | ----------- | --------------------------------- |
| All   | `camelCase` | `position`, `velocity`, `isAlive` |

---

## Variable Naming

### Local Variables

| Scope | Convention  | Example                        |
| ----- | ----------- | ------------------------------ |
| Local | `camelCase` | `index`, `count`, `tempBuffer` |

### Global Variables

| Scope         | Convention         | Example                           |
| ------------- | ------------------ | --------------------------------- |
| Public Global | `gPascalCase`      | `gRenderContext`, `gAudioManager` |
| Static Global | `static camelCase` | `static frameCount`               |

---

## Constants and Macros

| Type         | Convention    | Example                     |
| ------------ | ------------- | --------------------------- |
| Macro Define | `ALL_CAPS`    | `MAX_ENTITIES`, `TILE_SIZE` |
| Const Var    | `PascalCase`  | `DefaultSpeed`, `Gravity`   |
| Enum Values  | `PREFIX_CAPS` | `STATE_IDLE`, `COLOR_RED`   |

---

## File Names

| Type            | Convention              | Example             |
| --------------- | ----------------------- | ------------------- |
| Source File     | `snake_case.c`          | `entity.c`          |
| Header File     | `snake_case.h`          | `entity.h`          |
| Internal Header | `snake_case_internal.h` | `entity_internal.h` |

---

## Module Prefixing (Required)

All functions must be prefixed with the module name to prevent symbol collisions and clarify ownership.

```c
// entity.h
Entity* entityCreate(void);
void entityDestroy(Entity* e);

// audio.h
void audioInit(void);
void audioPlaySound(Sound* s);

// entity_internal.c
static void entityUpdateInternal(void);
void internal_entityLoadTexture(void);
```

This applies to **all public, private, and static functions**.

---

## Summary Table

| Category         | Convention                            | Example                                |
| ---------------- | ------------------------------------- | -------------------------------------- |
| Public Function  | `camelCase` with module prefix        | `entityInitRenderer`                   |
| Private Function | `camelCase` with `internal_` prefix   | `internal_entityUpdateEntity`          |
| Static Function  | `static camelCase` with module prefix | `static entityLoadTexture`             |
| Struct Type      | `PascalCase`                          | `Entity`, `RenderBatch`                |
| Private Struct   | `PascalCase` with `Internal` suffix   | `EntityInternal`, `AudioStateInternal` |
| Struct Field     | `camelCase`                           | `x`, `y`, `healthPoints`               |
| Local Variable   | `camelCase`                           | `temp`, `frame`, `score`               |
| Global Variable  | `gPascalCase`                         | `gRenderContext`                       |
| Static Variable  | `static camelCase`                    | `static deltaTime`                     |
| Macro Constant   | `ALL_CAPS`                            | `TILE_SIZE`, `MAX_ENTITIES`            |
| Enum Value       | `PREFIX_CAPS`                         | `STATE_IDLE`, `COLOR_RED`              |
| Const Literal    | `PascalCase`                          | `DefaultSpeed`                         |
| File Names       | `snake_case`                          | `entity.c`, `tile_map.h`               |

---

## Note On Module Prefixing

Module prefixing should be treated as a core part of the naming convention. It improves clarity, enforces namespacing in C where none exists by default, and supports modular project design. Each function name should clearly indicate which subsystem or module it belongs to, making the codebase easier to navigate and maintain.
