package de.timkraut.consistec_programming_contest;

/**
 * A given object is null.
 *
 * @author Tim Kraut
 */
public class ObjectNullException extends Exception {
    public ObjectNullException() {
        super();
    }

    public ObjectNullException(String msg) {
        super(msg);
    }
}
