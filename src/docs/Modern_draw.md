# OpenGL 和 GLFW API 调用清单 (按执行顺序)

## 1. 初始化 GLFW 和创建窗口
1. **`glfwInit()`**  
   - 初始化 GLFW 库。

2. **`glfwCreateWindow(int width, int height, const char* title, GLFWmonitor* monitor, GLFWwindow* share)`**  
   - 创建一个 640x480 的窗口并命名为 `"Hello World"`。

3. **`glfwMakeContextCurrent(GLFWwindow* window)`**  
   - 将窗口的 OpenGL 上下文设置为当前上下文。

## 2. 初始化 GLEW
4. **`glewInit()`**  
   - 初始化 GLEW 以确保 OpenGL 函数可用。

5. **`glGetString(GLenum name)`**  
   - 获取当前的 OpenGL 版本信息，`name` 为 `GL_VERSION`。

## 3. 顶点缓冲对象 (VBO) 设置
6. **`glGenBuffers(GLsizei n, GLuint* buffers)`**  
   - 生成一个缓冲对象的句柄。

7. **`glBindBuffer(GLenum target, unsigned int buffer)`**  
   - 绑定缓冲区到目标（`GL_ARRAY_BUFFER`），用于存储顶点数据。

8. **`glBufferData(GLenum target, GLsizeiptr size, const void* data, GLenum usage)`**  
   - 为顶点缓冲区分配内存并上传顶点数据。

## 4. 启用顶点属性数组
9. **`glEnableVertexAttribArray(unsigned int index)`**  
   - 启用位置为 `0` 的顶点属性数组。

10. **`glVertexAttribPointer(unsigned int index, int size, GLenum type, GLboolean normalized, GLsizei stride, const void* pointer)`**  
    - 设置顶点属性数组的格式：每个顶点有两个 `GL_FLOAT` 类型的坐标。

## 5. 编译顶点和片段着色器
11. **`glCreateShader(unsigned int type)`**  
    - 创建一个顶点着色器对象。

12. **`glShaderSource(unsigned int shader, GLsizei count, const char** string, const GLint* length)`**  
    - 设置顶点着色器的源代码。

13. **`glCompileShader(unsigned int shader)`**  
    - 编译顶点着色器。

14. **`glGetShaderiv(unsigned int shader, GLenum pname, GLint* params)`**  
    - 检查顶点着色器的编译状态（`GL_COMPILE_STATUS`）。

15. **`glGetShaderInfoLog(unsigned int shader, GLsizei maxLength, GLsizei* length, char* infoLog)`**  
    - 如果编译失败，获取编译错误信息。

16. **`glDeleteShader(unsigned int shader)`**  
    - 如果编译失败，删除顶点着色器对象。

17. **`glCreateShader(unsigned int type)`**  
    - 创建一个片段着色器对象。

18. **`glShaderSource(unsigned int shader, GLsizei count, const char** string, const GLint* length)`**  
    - 设置片段着色器的源代码。

19. **`glCompileShader(unsigned int shader)`**  
    - 编译片段着色器。

20. **`glGetShaderiv(unsigned int shader, GLenum pname, GLint* params)`**  
    - 检查片段着色器的编译状态（`GL_COMPILE_STATUS`）。

21. **`glGetShaderInfoLog(unsigned int shader, GLsizei maxLength, GLsizei* length, char* infoLog)`**  
    - 如果编译失败，获取编译错误信息。

22. **`glDeleteShader(unsigned int shader)`**  
    - 如果编译失败，删除片段着色器对象。

## 6. 创建和链接着色器程序
23. **`glCreateProgram()`**  
    - 创建一个程序对象。

24. **`glAttachShader(unsigned int program, unsigned int shader)`**  
    - 将顶点着色器附加到程序对象。

25. **`glAttachShader(unsigned int program, unsigned int shader)`**  
    - 将片段着色器附加到程序对象。

26. **`glLinkProgram(unsigned int program)`**  
    - 链接程序对象。

27. **`glValidateProgram(unsigned int program)`**  
    - 验证程序对象是否可以在当前的 OpenGL 状态下使用。

28. **`glDeleteShader(unsigned int shader)`**  
    - 删除顶点着色器对象（已链接到程序，不再需要单独的着色器对象）。

29. **`glDeleteShader(unsigned int shader)`**  
    - 删除片段着色器对象。

30. **`glUseProgram(unsigned int program)`**  
    - 将链接后的程序设置为当前活动的着色器程序。

## 7. 渲染循环
31. **`glClear(GLbitfield mask)`**  
    - 清除颜色缓冲区。

32. **`glDrawArrays(GLenum mode, GLint first, GLsizei count)`**  
    - 绘制三角形，使用当前激活的着色器程序和顶点数组。

33. **`glfwSwapBuffers(GLFWwindow* window)`**  
    - 交换前后台缓冲区，显示绘制结果。

34. **`glfwPollEvents()`**  
    - 检查并处理输入事件（如键盘、鼠标）。

35. **`glfwWindowShouldClose(GLFWwindow* window)`**  
    - 检查窗口是否应该关闭。

## 8. 退出和清理
36. **`glDeleteProgram(unsigned int program)`**  
    - 删除着色器程序。

37. **`glfwTerminate()`**  
    - 终止 GLFW，释放所有资源。
