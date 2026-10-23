interface Drink{
    String getDescription();
    int getPrice();
}

class Juice implements Drink{
    @Override
    public String getDescription() {
        return "Juice";
    }

    @Override
    public int getPrice() {
        return 100;
    }
}

class Soda implements Drink{
    @Override
    public String getDescription() {
        return "Soda";
    }

    @Override
    public int getPrice() {
        return 200;
    }
}

abstract class DrinkDecorator implements Drink{
    protected final Drink drink;

    public DrinkDecorator(Drink drink){
        this.drink = drink;
    }
}

class MilkDecorator extends DrinkDecorator{
    public MilkDecorator(Drink drink){
        super(drink);
    }

    @Override
    public String getDescription() {
        return drink.getDescription() + ", milk";
    }

    @Override
    public int getPrice() {
        return drink.getPrice() + 100;
    }
}

class CaramelDecorator extends DrinkDecorator{
    public CaramelDecorator(Drink drink){
        super(drink);
    }

    @Override
    public String getDescription() {
        return drink.getDescription() + ", caramel";
    }

    @Override
    public int getPrice() {
        return drink.getPrice() + 120;
    }
}

public class DecoratorExample{
    static void main() {
        Drink drink = new Juice();

        drink = new CaramelDecorator(drink);
        drink = new MilkDecorator(drink);

        System.out.println(drink.getDescription());
    }
}