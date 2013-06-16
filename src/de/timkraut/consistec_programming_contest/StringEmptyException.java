package de.timkraut.consistec_programming_contest;

/**
 * A string is empty.
 *
 * @author Tim Kraut
 */
public class StringEmptyException extends Exception {
    // Error constants
    private static final String ERR_STRING_IS_EMPTY = " is an empty string.\n";

    public StringEmptyException() {
        super();
    }

    public StringEmptyException(String msg) {
        super(msg);
    }

    /**
     * Throws an exception if the given string is empty.
     *
     * @param string String to check.
     *
     * @throws StringEmptyException Given string is empty.
     */
    public static void checkStringNotEmpty(String string) throws StringEmptyException {
        if (string.trim().isEmpty()) {
            throw new StringEmptyException(string + ERR_STRING_IS_EMPTY);
        }
    }
}
