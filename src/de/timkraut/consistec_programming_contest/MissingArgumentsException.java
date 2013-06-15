package de.timkraut.consistec_programming_contest;

/**
 * Less arguments than expected are given.
 *
 * @author Tim Kraut
 */
public class MissingArgumentsException extends Exception {
    public MissingArgumentsException() {
        super();
    }

    public MissingArgumentsException(String msg) {
        super(msg);
    }
}
