project('GenericRenderer', 'c',
        version : '1.0.0',
        default_options : ['warning_level=3', 'c_std=c18'])

lib_args = ['-DBUILDING_MESON_LIBRARY']

subdir('vendor/glad')

glfw = dependency('glfw3', required: true)

sources = files('src/window.c')

renderer = static_library('GenericRenderer', sources, dependencies: [ glfw, glad ])

executable('example', 'example/example.c', link_with: renderer)