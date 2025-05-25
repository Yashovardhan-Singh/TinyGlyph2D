/*
 * Minimal hello triangle example, we refactor into a library later
 * for now all code is here, for teaching purposes
 */

#include "../vendor/glad/gl.h"
#include <GLFW/glfw3.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Constants
#define WIDTH 1280
#define HEIGHT 720
#define NO_EXPORT static const  // mark as private

// vertex data
NO_EXPORT float vertices[6] = {
    // x, y
    -0.5, -0.5, // bottom left
    0.5, -0.5,  // bottom right
    0.0, 0.5    // top
};

// element data
// first vertex, then 2nd vertex, then 3rd vertex
NO_EXPORT uint32_t indices[3] = {
    0, 1, 2
};

NO_EXPORT size_t vertexCount = 6;
NO_EXPORT size_t indexCount = 3;

// This function is a callback to handle window resizing
// uses the concept of function pointers
// even though window parameter is not used, we still have to add it
// cause of function pointer shenanigans
void windowResizeCallback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

// Helper function to read files
const char* readFromFile(const char* filePath) {
    FILE *file = fopen(filePath, "r");
    if (!file) {
        fprintf(stderr, "Cannot open file as read: %s\n", filePath);
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    rewind(file);

    char *buffer = (char *)malloc(fileSize + 1);
    if (!buffer) {
        fprintf(stderr, "Memory Allocation Failed For Shader Source\n");
        fclose(file);
        return NULL;
    }

    fread(buffer, 1, fileSize, file);
    buffer[fileSize] = '\0';
    fclose(file);
    return (const char*) buffer;
}

int main() {

    // Initialise glfw library, and check if it failed or not
    if (!glfwInit()) {
        fprintf(stderr, "Failed to initialize GLFW3\n");
        exit(EXIT_FAILURE);
    }

    // Create a handle to window
    // Glfw window is an opaque type, which is why it needs to be a pointer
    // first parameter is window width, in pixels, second is height
    // third is title, 4th is the monitor on which we want to set fullscreen
    // since no full screen rn, so we pass null
    // 5th is share, dw about it
    GLFWwindow* win = glfwCreateWindow(WIDTH, HEIGHT, "Hello World!", NULL, NULL);

    // Let glfw window be aware of what version of opengl we want and what profile
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);  // major
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);  // minor
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // profile

    // Make the window the current graphical context target
    // all rendering will be done to the window that this handle points to
    glfwMakeContextCurrent(win);

    // attach the window resize callback to our window handle
    glfwSetFramebufferSizeCallback(win, windowResizeCallback);

    // load GLAD
    // while glfw handles windowing, glad handles loading the opengl functions for us
    // basically, looks at our drivers, and loads the necessary functions for us to use
    // we pass another function to this function, which gets the process address,
    // from the OS, of glfw
    if (!gladLoadGL(glfwGetProcAddress)) {
        fprintf(stderr, "Failed to initialize GLAD\n");
        glfwDestroyWindow(win);
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    // Get the current frambuffer width and height
    // Frame buffer is the buffer in which things are drawn
    // we want the height and width of it
    // so we can set the opengl viewport, what we see, normally
    int32_t fbWidth, fbHeight;
    glfwGetFramebufferSize(win, &fbWidth, &fbHeight);

    // set the opengl viewport
    glViewport(0, 0, fbWidth, fbHeight);

    // These are our rendering objects
    // VAO: vertex attribute object (tells the gpu how our array of data is structured)
    // VBO: vertex buffer object (array of data)
    // EBO: element buffer object (array of indexes of triangles we want to draw)
    int32_t VAO, VBO, EBO;

    // Generate the objects
    glGenVertexArrays(1, &VAO); // Generate a vertex attribute object
    glGenBuffers(1, &VBO); // Generate a vertex buffer object
    glGenBuffers(1, &EBO); //

    // A VAO just hold an integer value (unsigned > 0) (0 means no array bound)
    // what this means is that on the GPU, there is a slot for a vertex attribute object
    // calling glGenVertexArrays() adds it to the slot, and gives us the slot number
    // whenever we need to use that vertex attrib object, we just tell the gpu which slot number
    // then the rest gpu handles itself
    glBindVertexArray(VAO); // which slot do we want

    // this again the same slot thing, but this holds the slot of where we'll send all our data
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    // 1) target: We use an enum to specify that this is an array buffer
    // 2) size: we give it the size in bytes of our vertices
    // 3) data: we pass the array (it decays into a pointer so vertices is pointer to 1st element at index 0)
    // 4) usage: another enum to tell that the data in this buffer won't change often
    // this pushes our vertex data to the GPU
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Same thing as VBO, but we just do it for elements
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    // Same as VBO, but we pass elements
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // How is the data structured in the array we will pass
    // 1) index means which vertex attribute we want to modify
    // 2) size means how many components of that vertex attribute we want to specify
    // for 2d, that is 2 floats: x and y, so size is 2
    // 3) type means the type which we will pass, this is an enum given by opengl. We use floats
    // 4) normalized: we don't want normalized floats, dw about it
    // 5) stride: this basically means how far opengl should step to find the next element in our data array (in bytes)
    // for 2 components, we use 2 * sizeof(float) since we have x and y component with floats
    // 6) pointer: this basically means, how far from the start in bytes, does this element start
    // as this is first element, we say (void*) 0, i.e 0 bytes from start
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);   // Enable the first attribute

    // Unbind everything to prevent modification
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    // Read shader files
    const char* fragment_shader_source = readFromFile("../example/shaders/fragment.glsl");
    const char* vertex_shader_source = readFromFile("../example/shaders/vertex.glsl");

    // handles to shaders
    uint32_t fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    uint32_t vertex_shader = glCreateShader(GL_VERTEX_SHADER);

    // compile fragment shader, compilation happens on GPU, we just send the data
    // 1) pass the slot of which shader we want
    // 2) only one shader
    // 3) source of shader
    // 4) automatically determine length
    glShaderSource(fragment_shader, 1, &fragment_shader_source, NULL);
    glCompileShader(fragment_shader);   // This can often silently fail

    // Error handling in shader compilation
    uint32_t success;
    glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        char info[512];
        glGetShaderInfoLog(fragment_shader, sizeof(info), NULL, info);
        fprintf(stderr, "Shader compilation failed.\nLog:\n%s\n", info);
        glDeleteShader(fragment_shader);
        glDeleteVertexArrays(1, &VAO);
        glDeleteBuffers(1, &VBO);
        glDeleteBuffers(1, &EBO);
        glfwDestroyWindow(win);
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    // compile vertex shader
    glShaderSource(vertex_shader, 1, &vertex_shader_source, NULL);
    glCompileShader(vertex_shader);

    // Error handling again
    success = 0;
    glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        char info[512];
        glGetShaderInfoLog(vertex_shader, sizeof(info), NULL, info);
        fprintf(stderr, "Shader compilation failed.\nLog:\n%s\n", info);
        glDeleteShader(vertex_shader);
        glDeleteVertexArrays(1, &VAO);
        glDeleteBuffers(1, &VBO);
        glDeleteBuffers(1, &EBO);
        glfwDestroyWindow(win);
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    // we create a shader program, which will basically compile vertex and fragment into one and use it
    uint32_t shader_program = glCreateProgram();
    glAttachShader(shader_program, vertex_shader);
    glAttachShader(shader_program, fragment_shader);
    glLinkProgram(shader_program);

    // free pointers to file data (avoid memory leaks)
    free(fragment_shader_source);
    free(vertex_shader_source);

    // free space on gpu for shaders not needed
    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);

    // Error handling for shader program
    success = 0;
    glGetProgramiv(shader_program, GL_LINK_STATUS, &success);
    if(!success) {
        char info[512];
        glGetProgramInfoLog(shader_program, sizeof(info), NULL, info);
        fprintf(stderr, "Error linking shaders.\nLog:\n%s\n", info);
        glDeleteProgram(shader_program);
        glDeleteVertexArrays(1, &VAO);
        glDeleteBuffers(1, &VBO);
        glDeleteBuffers(1, &EBO);
        glfwDestroyWindow(win);
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    // Rebind buffer objects for drawing
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

    // Main loop
    while (!glfwWindowShouldClose(win)) {
        glClearColor(0.0, 0.0, 0.0, 1.0); // rgba black (range: 0.0 to 1.0)
        glClear(GL_COLOR_BUFFER_BIT);   // call to opengl to clear the buffer for redraw

        glUseProgram(shader_program);   // use our shaders
        glBindVertexArray(VAO);     // use the vertex array layout we specified
        // Draw elements using index array
        glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, (void*)0);

        // Window refereshing tasks
        glfwSwapBuffers(win);   // swap framebuffers
        glfwPollEvents();   // poll all window events like resize, close, minimize, etc
    }

    // Cleanup
    glDeleteProgram(shader_program);
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);

    // Clean up glfw
    glfwDestroyWindow(win);
    glfwTerminate();

    return 0;
}

/*
 * Basically, in to write a renderer we need to do the following things:
 * 1) Create and handle rendering objects (VAO, VBO, EBO, and later an FBO)
 * 2) Create and handle shaders
 * 3) Add a main loop
 * 4) De init everything
 * This is the first and the most simple thing we need to get down
 * We also need window management to render too
 */