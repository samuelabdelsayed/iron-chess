#pragma once

#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <string>
#include <memory>

namespace IronChess {

class Shader {
public:
    Shader(const std::string& vertexPath, const std::string& fragmentPath);
    ~Shader();
    
    void use() const;
    void setMatrix4(const std::string& name, const glm::mat4& matrix) const;
    void setVector3(const std::string& name, const glm::vec3& vector) const;
    void setFloat(const std::string& name, float value) const;
    void setInt(const std::string& name, int value) const;
    
private:
    GLuint programID;
    GLuint loadShader(const std::string& path, GLenum type) const;
    std::string readFile(const std::string& path) const;
};

class Texture {
public:
    explicit Texture(const std::string& path);
    ~Texture();
    
    void bind(int unit = 0) const;
    void unbind() const;
    
    int getWidth() const { return width; }
    int getHeight() const { return height; }
    
private:
    GLuint textureID;
    int width, height, channels;
};

class Mesh {
public:
    struct Vertex {
        glm::vec3 position;
        glm::vec3 normal;
        glm::vec2 texCoords;
    };
    
    Mesh(const std::vector<Vertex>& vertices, const std::vector<unsigned int>& indices);
    ~Mesh();
    
    void render() const;
    
private:
    GLuint VAO, VBO, EBO;
    size_t indexCount;
};

class Model {
public:
    explicit Model(const std::string& path);
    
    void render(const Shader& shader) const;
    void setTexture(std::shared_ptr<Texture> texture) { this->texture = texture; }
    
private:
    std::vector<std::unique_ptr<Mesh>> meshes;
    std::shared_ptr<Texture> texture;
    
    void loadModel(const std::string& path);
};

class Camera {
public:
    Camera(glm::vec3 position = glm::vec3(0.0f, 5.0f, 10.0f));
    
    glm::mat4 getViewMatrix() const;
    glm::mat4 getProjectionMatrix(float aspectRatio) const;
    
    void setPosition(const glm::vec3& pos) { position = pos; }
    void setTarget(const glm::vec3& target) { this->target = target; }
    void setFOV(float fov) { this->fov = fov; }
    
    glm::vec3 getPosition() const { return position; }
    glm::vec3 getTarget() const { return target; }
    
    // Camera controls
    void orbit(float deltaX, float deltaY);
    void zoom(float delta);
    void pan(float deltaX, float deltaY);
    
private:
    glm::vec3 position;
    glm::vec3 target;
    glm::vec3 up;
    float fov;
    float near_plane;
    float far_plane;
    
    // Orbital camera parameters
    float radius;
    float theta; // horizontal angle
    float phi;   // vertical angle
    
    void updatePosition();
};

} // namespace IronChess