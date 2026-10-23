interface Image{
    void display();
}

class RealImage implements Image{
    private final String name;

    public RealImage(String name){
        this.name = name;
        loadFromDisk();
    }

    private void loadFromDisk(){
        System.out.println("Loading from Disk!");
    }

    @Override
    public void display() {
        System.out.println("Image Displayed " + name);
    }
}

class ImageProxy implements Image{
    private final String name;
    private Image realImage;

    public ImageProxy(String name){
        this.name = name;
    }

    @Override
    public void display() {
        if (realImage == null)
            realImage = new RealImage(name);

        realImage.display();
    }
}

public class ProxyExample{
    static void main() {
        Image image = new ImageProxy("largePhoto.jpg");

        image.display();
    }
}