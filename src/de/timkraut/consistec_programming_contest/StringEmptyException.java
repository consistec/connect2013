package de.timkraut.consistec_programming_contest;

/**
 * An string which is empty.
 *
 * @author Tim Kraut
 */
public class StringEmptyException extends Exception {
    public StringEmptyException() {
        super();
    }

    public StringEmptyException(String msg) {
        super(msg);
    }
}
