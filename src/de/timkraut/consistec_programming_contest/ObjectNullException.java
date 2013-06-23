package de.timkraut.consistec_programming_contest;

/**
 * A given object is null.
 *
 * @author Tim Kraut
 */
public class ObjectNullException extends Exception {
    // Error constants
    private static final String ERR_OBJ_IS_NULL = " is null.\n";

    public ObjectNullException() {
        super();
    }

    public ObjectNullException(String msg) {
        super(msg);
    }

    /**
     * Throws an exception if the given object is null.
     *
     * @param obj Object to check.
     *
     * @throws ObjectNullException Given object is null.
     */
    public static void checkNotNull(Object obj) throws ObjectNullException {
        if (obj == null) {
            throw new ObjectNullException(obj + ERR_OBJ_IS_NULL);
        }
    }
}
