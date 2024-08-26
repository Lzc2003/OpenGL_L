#include<GL/glew.h>
#include <GLFW/glfw3.h>
#include<iostream>

static unsigned int CompileShader(unsigned int type,const std::string& souce)
{
    unsigned int id =glCreateShader(type);
    const char* src = souce.c_str();
    glShaderSource(id, 1, &src, nullptr);
    glCompileShader(id);
    int result;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);
    if (result == GL_FALSE)
    {
        int LENGTH;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &LENGTH);
        char* message = (char*)alloca(LENGTH * sizeof(char));
        glGetShaderInfoLog(id, LENGTH, &LENGTH, message);
        std::cout << message << std::endl;
        glDeleteShader(id);
        return 0;

    }
    return id;
}

static unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader)
{
    unsigned int program = glCreateProgram();
    unsigned int vs = CompileShader(GL_VERTEX_SHADER,vertexShader);
    unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

    glAttachShader(program, vs);
    glAttachShader(program, fs);
    glLinkProgram(program);
    glValidateProgram(program);

    glDeleteShader(vs);
    glDeleteShader(fs);

    return program;

}
int main(void)
{
    GLFWwindow* window;
    if (!glfwInit())    return -1;
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);

    if (!window)
    {
        glfwTerminate(); 
        return -1; 
    }

    glfwMakeContextCurrent(window);
    if (glewInit() != GLEW_OK)  std::cout << "error" << std::endl;
    std::cout << glGetString(GL_VERSION) << std::endl;

    float position[6] = {
       -0.5f, -0.5f,
        0.5f, -0.5f,
        0.0f,  0.5f
    };

    unsigned int buffer;
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), position, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

    std::string vertexShader =
        "#version 330 core\n"
        "\n"
        "layout(location = 0) in vec4 position;\n"
        "\n"
        "void main()\n"
        "{\n"
        "   gl_Position=position;\n"

        "}\n";
    std::string fragmentShader =
        "#version 330 core\n"
        "\n"
        "out vec4 color;\n"
        "\n"
        "void main()\n"
        "{\n"
        "   color=vec4(1.0,0.5,0.0,1.0);\n"

        "}\n";

    unsigned int shader = CreateShader(vertexShader, fragmentShader);
    glUseProgram(shader);

    while (!glfwWindowShouldClose(window))
    {

        glClear(GL_COLOR_BUFFER_BIT); 
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glfwSwapBuffers(window);
        glfwPollEvents();

    }
    glDeleteProgram(shader);

    glfwTerminate();
    return 0; 
}
