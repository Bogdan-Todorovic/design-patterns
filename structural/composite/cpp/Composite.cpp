#include <iostream>
#include <vector>

class FileSystemComponent {
public:
    virtual int getSize() = 0;
    virtual ~FileSystemComponent() = default;
};

class File : public FileSystemComponent {
private:
    std::string name;
    int size{};

public:
    File(std::string name, int size) : name(std::move(name)), size(size){}
    int getSize() override {
        return size;
    }
};

class Folder : public FileSystemComponent {
private:
    std::string name;
    std::vector<std::unique_ptr<FileSystemComponent>> children;

public:
    explicit Folder(std::string name) : name(std::move(name)){}

    void add(std::unique_ptr<FileSystemComponent> child) {
        children.push_back(std::move(child));
    }

    int getSize() override {
        int total = 0;
        for (const auto &c : children)
            total += c->getSize();

        return total;
    }
};

int main() {
    auto documents = std::make_unique<Folder>("Documents");

    documents->add(std::make_unique<File>("document.pdf", 2));
    documents->add(std::make_unique<File>("notes.txt", 1));

    auto projects = std::make_unique<Folder>("Projects");
    projects->add(std::make_unique<File>("app.cpp", 3));

    documents->add(std::move(projects));

    std::cout << documents->getSize() << " MB\n";
}