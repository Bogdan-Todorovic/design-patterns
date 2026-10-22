import java.util.ArrayDeque;
import java.util.Deque;

// Originator
class Editor {
    private String text = "";
    public void write(String newText){
        text += newText;
    }

    public String getText(){
        return text;
    }

    public Memento save(){
        return new Memento(text);
    }

    public void restore(Memento memento){
        text = memento.getSavedText();
    }

    static class Memento {
        private final String savedText;

        private Memento(String savedText){
            this.savedText = savedText;
        }

        private String getSavedText(){
            return savedText;
        }
    }
}

// Caretaker
class History {
    private final Deque<Editor.Memento> states = new ArrayDeque<>();

    public void save(Editor editor){
        states.push(editor.save());
    }

    public void undo(Editor editor){
        if (!states.isEmpty())
            editor.restore(states.pop());
    }
}

// Client
public class MementoExample{
    static void main() {
        Editor editor = new Editor();
        History history = new History();

        editor.write("Zdravo");
        history.save(editor);

        editor.write(" svima!");
        history.save(editor);

        System.out.println(editor.getText());

        history.undo(editor);

        System.out.println(editor.getText());
    }
}
