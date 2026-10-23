import java.util.HashMap;
import java.util.Map;

class BulletType{
    private final String texture;
    private final int damage;

    public BulletType(String texture, int damage){
        this.texture = texture;
        this.damage = damage;
    }

    public void render(int x, int y){
        System.out.println("Rendering " + texture + "bullet "
                + "at " + x + " " + y + ", "
                + "damage " + damage);
    }
}

class BulletTypeFactory{
    private final Map<String, BulletType> types = new HashMap<>();

    public BulletType getType(String name, String texture, int damage){
        return types.computeIfAbsent(name, key -> new BulletType(texture, damage));
    }
}

class Bullet{
    private final BulletType type;
    private int x;
    private int y;

    public Bullet(BulletType type, int x, int y){
        this.type = type;
        this.x = x;
        this.y = y;
    }

    public void render(){
        type.render(x, y);
    }

    public void move(int dx, int dy){
        this.x += dx;
        this.y += dy;
    }
}

public class FlyweightExample{
    static void main() {
        BulletTypeFactory bulletTypeFactory = new BulletTypeFactory();

        BulletType normalBullet = bulletTypeFactory.getType("normal", "normal", 10);
        Bullet bullet1 = new Bullet(normalBullet, 2, 5);
        Bullet bullet2 = new Bullet(bulletTypeFactory.getType("normal", "normal", 10), 50, 70);

        bullet1.render();
        bullet2.render();

        bullet1.move(5, 5);
        bullet1.render();
        bullet2.render();
    }
}