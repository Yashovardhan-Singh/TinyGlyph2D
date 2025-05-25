project('GenericRenderer', 'c',
        version : '1.0.0',
        default_options : ['warning_level=3', 'c_std=c18'])

# Arguments
lib_args = ['-DBUILDING_MESON_LIBRARY']

# Project subdirectories
subdir('vendor/glad')

# Dependencies
glfw = dependency('glfw3', required: true)

# Project files
sources = files('src/window.c')
include = include_directories('src')

# Targets
renderer = static_library('GenericRenderer', sources, include_directories: include, dependencies: [ glfw, glad ])
example = executable('example', 'example/example.c', include_directories: include, link_with: renderer)
tutorial = executable('tutorial', 'example/tutorial.c', dependencies: [ glfw, glad ])