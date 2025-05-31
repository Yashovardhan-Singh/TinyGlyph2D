vector_test = executable(
    'vector_tests',
    'vector_tests.c',
    include_directories: include_directories('.', '../src'),
    link_with: renderer
)

test('Vector Operations', vector_test)