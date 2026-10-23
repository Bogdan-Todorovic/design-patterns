import java.util.ArrayList;
import java.util.List;

interface FileSystemComponent{
    int getSize();
}

class File implements FileSystemComponent{
    private final String name;
    private final int size;

    public File(String name, int size){
        this.name = name;
        this.size = size;
    }

    @Override
    public int getSize() {
        return size;
    }
}

class Folder implements FileSystemComponent{
    private final String name;
    private final List<FileSystemComponent> children = new ArrayList<>();

    public Folder(String name){
        this.name = name;
    }

    public void add(FileSystemComponent child){
        children.add(child);
    }
    @Override
    public int getSize() {
        int sum = 0;
        for (FileSystemComponent fsc : children)
            sum += fsc.getSize();

        return sum;
    }
}

public class CompositeExample {
    static void main(String[] args) {
        File file1 = new File("document.pdf", 2);
        File file2 = new File("notes.txt", 1);
        File file3 = new File("app.cpp", 3);

        Folder projects = new Folder("Projects");
        projects.add(file3);

        Folder documents = new Folder("Documents");
        documents.add(file1);
        documents.add(file2);
        documents.add(projects);

        System.out.println(file1.getSize() + " MB");
        System.out.println(projects.getSize() + " MB");
        System.out.println(documents.getSize() + " MB");
    }
}