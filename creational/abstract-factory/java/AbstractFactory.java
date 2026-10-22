// Interface of products that all factories derived from Abstract factory must implement
interface Button {
    void render();
}

interface CheckBox {
    void render();
}

// Implementing concrete Windows Button
class WindowsButton implements Button {

    @Override
    public void render() {
        System.out.println("Rendering Windows Button");
    }
}

// Implementing concrete Windows CheckBox
class WindowsCheckBox implements CheckBox {
    @Override
    public void render(){
        System.out.println("Rendering Windows CheckBox");
    }
}

// Implementing concrete Mac Button
class MacButton implements Button {
    @Override
    public void render() {
        System.out.println("Rendering Mac Button");
    }
}

// Implementing concrete Mac CheckBox
class MacCheckBox implements CheckBox {
    @Override
    public void render(){
        System.out.println("Rendering Mac CheckBox");
    }
}

// Abstract factory that defines all the products
interface GUIFactory {
    Button createButton();
    CheckBox createCheckBox();
}

// Concrete Windows Factory that implements Windows elements
class WindowsFactory implements GUIFactory {
    @Override
    public Button createButton() {
        return new WindowsButton();
    }

    @Override
    public CheckBox createCheckBox() {
        return new WindowsCheckBox();
    }
}

// Concrete Mac Factory that implements Mac elements
class MacFactory implements GUIFactory {
    @Override
    public Button createButton() {
        return new MacButton();
    }

    @Override
    public CheckBox createCheckBox() {
        return new MacCheckBox();
    }
}

// Client's code
public class AbstractFactory {
    static void main() {
        // Client only has to change what type of factory he uses
        // Rest of the code stays the same but now elements that are being produces has changed.
        GUIFactory factory = new WindowsFactory();
        // GUIFactory factory = new MacFactory();

        Button button = factory.createButton();
        CheckBox checkBox = factory.createCheckBox();

        button.render();
        checkBox.render();
    }
}
