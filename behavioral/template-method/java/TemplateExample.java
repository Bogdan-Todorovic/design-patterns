abstract class Beverage {
    // Template Method
    public final void prepare(){
        boilWater();
        brew();
        pourIntoCup();
        addCondiments();
    }

    private void boilWater(){
        System.out.println("Boiling water");
    }

    protected abstract void brew();

    private void pourIntoCup(){
        System.out.println("Pouring into cup");
    }

    // Optional hook operation
    protected void addCondiments(){
        // Default do nothing
    }
}

class Coffee extends Beverage {
    @Override
    protected void brew() {
        System.out.println("Brewing coffee");
    }
}

class Tea extends Beverage {
    @Override
    protected void brew() {
        System.out.println("Brewing tea");
    }

    @Override
    protected void addCondiments() {
        System.out.println("Adding Lemon");
    }
}

public class TemplateExample{
    static void main() {
        Beverage coffee = new Coffee();
        Beverage tea = new Tea();

        coffee.prepare();
        tea.prepare();
    }
}
