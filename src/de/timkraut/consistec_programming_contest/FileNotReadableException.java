package de.timkraut.consistec_programming_contest;

/**
 * A file is not readable.
 *
 * @author Tim Kraut
 */
public class FileNotReadableException extends Exception {
    public FileNotReadableException() {
        super();
    }

    public FileNotReadableException(String msg) {
        super(msg);
    }
}
