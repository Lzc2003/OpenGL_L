#include <GLFW/glfw3.h> // 引入GLFW库的头文件，用于创建窗口、处理OpenGL上下文及输入输出事件

int main(void)
{
    GLFWwindow* window; // 定义一个指向GLFW窗口对象的指针

    /* 初始化GLFW库 */
    if (!glfwInit()) // 调用glfwInit函数初始化GLFW库，如果初始化失败返回-1
        return -1;

    /* 创建一个窗口，并为其分配OpenGL上下文 */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL); 
    // 创建一个窗口，大小为640x480，标题为"Hello World"，不指定共享上下文和监视器（即窗口模式）

    if (!window) // 如果窗口创建失败
    {
        glfwTerminate(); // 终止GLFW库，释放资源
        return -1; // 返回-1表示错误
    }

    /* 使窗口的上下文成为当前线程的主上下文 */
    glfwMakeContextCurrent(window); 
    // 设置刚刚创建的窗口的OpenGL上下文为当前线程的主上下文，这样后续的OpenGL指令才会作用于该窗口

    /* 当用户没有关闭窗口时，循环运行 */
    while (!glfwWindowShouldClose(window)) 
    {
        /* 在这里渲染内容 */
        glClear(GL_COLOR_BUFFER_BIT); // 清除颜色缓冲区，准备进行新的绘制

        glBegin(GL_TRIANGLES); // 开始定义一个三角形
        glVertex2f(-0.5f, -0.5f); // 定义第一个顶点的坐标
        glVertex2f(0.5f, -0.5f); // 定义第二个顶点的坐标
        glVertex2f(0.f, 0.5f); // 定义第三个顶点的坐标
        glEnd(); // 结束三角形的定义

        /* 交换前后缓冲区，显示渲染结果 */
        glfwSwapBuffers(window); 
        // 交换前缓冲区和后缓冲区，前缓冲区用于显示，后缓冲区用于绘制

        /* 轮询和处理事件 */
        glfwPollEvents(); 
        // 处理用户输入事件，比如键盘、鼠标等，并更新窗口状态
    }

    /* 终止GLFW库，释放资源 */
    glfwTerminate(); 
    return 0; // 程序结束，返回0表示成功执行
}
