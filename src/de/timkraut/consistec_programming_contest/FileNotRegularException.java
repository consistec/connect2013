package de.timkraut.consistec_programming_contest;

/**
 * A file is not a regular file.
 *
 * @author Tim Kraut
 */
public class FileNotRegularException extends Exception {
    public FileNotRegularException() {
        super();
    }

    public FileNotRegularException(String msg) {
        super(msg);
    }
}
