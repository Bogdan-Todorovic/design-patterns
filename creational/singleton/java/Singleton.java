public class Singleton {
    // Only instance of a class
    private static Singleton instance;

    // Constructor is private
    private Singleton(){
        System.out.println("Singleton Created");
    }

    // Static method for getting the only instance
    public static Singleton getInstance(){
        if (instance == null)
            instance = new Singleton();

        return instance;
    }

    public void doSomething(){
        System.out.println("Singleton Working");
    }

    // Test program
    static void main() {
        Singleton first = Singleton.getInstance();
        Singleton second = Singleton.getInstance();

        first.doSomething();

        System.out.println("Same instance: " + (first == second));
    }
}
