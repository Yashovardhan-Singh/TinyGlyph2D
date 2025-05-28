project('GenericRenderer', 'c',
        version : '1.0.0',
        default_options : ['warning_level=3', 'c_std=c18']
)

# Project subdirectories
subdir('vendor/glad')
subdir('src')

# Dependencies
glfw = dependency('glfw3', required: true)

# Compiler flags
lib_args = ['-DBUILDING_MESON_LIBRARY', '-DEXPORT_ENABLED']
if get_option('default_library') == 'shared'
        lib_args += ['-DBUILD_SHARED']
endif

# Library
renderer = library(
        'GenericRenderer',
        sources,
        include_directories: include,
        dependencies: [ glfw, glad ],
        c_args: lib_args,
        install: true
)

# Examples
example = executable(
        'example',
        'example/example.c',
        include_directories: include,
        link_with: renderer
)

tutorial = executable(
        'tutorial',
        'example/tutorial.c',
        dependencies: [ glfw, glad ],
)