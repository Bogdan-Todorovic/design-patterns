interface Prototype {
    Prototype clone();
}

class Enemy implements Prototype{
    private String name;
    private int health;
    private int armor;

    public Enemy(String name, int health, int armor){
        this.name = name;
        this.health = health;
        this.armor = armor;
    }

    @Override
    public Enemy clone() {
        return new Enemy(name, health, armor);
    }

    public void setHealth(int health) {
        this.health = health;
    }

    public void display(){
        System.out.println(name + ": health = " + health + " armor = " + armor);
    }
}

class PrototypeExample{
    static void main() {
        Enemy original = new Enemy("Goblin", 100, 200);
        Enemy copy = original.clone();

        copy.setHealth(120);

        original.display();
        copy.display();
    }
}