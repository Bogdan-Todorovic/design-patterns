class Character {
    private final String name;
    private final String weapon;
    private final String armor;
    private final int health;
    private final double speed;

    private Character(Builder builder){
        this.name = builder.name;
        this.weapon = builder.weapon;
        this.armor = builder.armor;
        this.health = builder.health;
        this.speed = builder.speed;
    }

    public void display() {
        System.out.println("Character: " + name);
        System.out.println("Weapon: " + weapon);
        System.out.println("Armor: " + armor);
        System.out.println("Health: " + health);
        System.out.println("Speed: " + speed);
    }

    public static class Builder {
        private final String name;
        private String weapon = "none";
        private String armor = "none";
        private int health = 100;
        private double speed = 0.5;

        public Builder (String name){
            this.name = name;
        }

        public Builder weapon (String weapon){
            this.weapon = weapon;
            return this;
        }

        public Builder armor (String armor){
            this.armor = armor;
            return this;
        }

        public Builder health (int health){
            this.health = health;
            return this;
        }

        public Builder speed (double speed){
            this.speed = speed;
            return this;
        }

        public Character build(){
            return new Character(this);
        }
    }
}

public class BuilderExample {
    static void main() {
        Character knight = new Character.Builder("Steve")
                .weapon("Sword")
                .armor("Heavy Armor")
                .health(150)
                .speed(0.3)
                .build();

        Character archer = new Character.Builder("Aron")
                .weapon("Bow and Arrow")
                .health(120)
                .speed(1)
                .build();

        knight.display();
        System.out.println();
        archer.display();
    }
}
