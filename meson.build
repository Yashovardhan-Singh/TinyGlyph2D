project('GenericRenderer', 'c',
        version : '1.0.0',
        default_options : ['warning_level=3', 'c_std=c18']
)

# ─────────────────────────────────────────────
# Compiler
# ─────────────────────────────────────────────
cc = meson.get_compiler('c')

# ─────────────────────────────────────────────
# Dependencies
# ─────────────────────────────────────────────
glfw = dependency('glfw3', required: true)
mathlib = cc.find_library('m', required: true)

# ─────────────────────────────────────────────
# Subdirectories
# ─────────────────────────────────────────────
subdir('vendor/glad')
subdir('src')

# ─────────────────────────────────────────────
# Include Path
# ─────────────────────────────────────────────
include = include_directories('src')

# ─────────────────────────────────────────────
# Preprocessor Defines
# ─────────────────────────────────────────────
lib_defines = ['-DBUILDING_MESON_LIBRARY', '-DEXPORT_ENABLED']

if get_option('default_library') == 'shared'
        lib_defines += ['-DBUILD_SHARED']
endif

# ─────────────────────────────────────────────
# Build Library
# ─────────────────────────────────────────────
renderer = library(
        'GenericRenderer',
        sources,
        include_directories: include,
        dependencies: [glfw, glad, mathlib],
        c_args: lib_defines,
        install: true
)


# ─────────────────────────────────────────────
# Tests
# ─────────────────────────────────────────────
subdir('test')

# ─────────────────────────────────────────────
# Build Examples
# ─────────────────────────────────────────────
example = executable(
        'example',
        'example/example.c',
        include_directories: include,
        link_with: renderer
)

tutorial = executable(
        'tutorial',
        'example/tutorial.c',
        dependencies: [glfw, glad],
        include_directories: include
)