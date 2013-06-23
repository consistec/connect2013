package de.timkraut.consistec_programming_contest;

/**
 * Encode characters according to the algorithm refactored from the sample files.
 *
 * @author Tim Kraut
 */
public final class ConsistecAlgorithm {
    /**
     * Prevent instantiating.
     */
    private ConsistecAlgorithm() {}

    /**
     * Encodes the given string according to the following algorithm:
     * <h1>Upper case characters</h1>
     * <pre>
     * A   = ASCII value + 12
     * B-M = ASCII value - 1
     * N-Y = ASCII value + 1
     * Z   = ASCII value - 12
     * </pre>
     * <h1>Lower case characters</h1>
     * <pre>
     * a-k = ASCII value + 2
     * l-m = ASCII value - 11
     * n-o = ASCII value + 11
     * p-z = ASCII value - 2
     * </pre>
     *
     * @param string String to encode.
     *
     * @return Encoded string.
     *
     * @throws ObjectNullException String is null.
     * @throws StringEmptyException String is empty.
     */
    public static String encode(String string) throws ObjectNullException, StringEmptyException {
        String returnString = "";

        for (int pos = 0; pos < string.length(); pos++) {
            returnString += (char) encodeChar(string.charAt(pos));
        }

        return returnString;
    }

    /**
     * Encodes a single character.
     *
     * @param character Character to encode.
     *
     * @return Encoded character.
     */
    private static int encodeChar(char character) {
        int ascii = (int) character;

        if ((ascii >= 65) && (ascii <= 90)) {
            // upper case character
            return encodeUpperCaseChar(ascii);
        } else if ((ascii >= 97) && (ascii <= 122)) {
            // lower case character
            return encodeLowerCaseChar(ascii);
        } else {
            return character;
        }
    }

    /**
     * Encodes upper case characters.
     *
     * @param ascii ASCII code of the characters to encode.
     *
     * @return ASCII code of the encoded character.
     */
    private static int encodeUpperCaseChar(int ascii) {
        // upper case character
        if (ascii == 65) {
            // = A
            return ascii + 12;


        } else if ((ascii >= 66) && (ascii <= 77)) {
            // = B to M
            return ascii - 1;


        } else if ((ascii >= 78) && (ascii <= 89)) {
            // = N to Y
            return ascii + 1;


        } else {
            // = Z
            return ascii - 12;
        }
    }

    /**
     * Encodes lower case characters.
     *
     * @param ascii ASCII code of the characters to encode.
     *
     * @return ASCII code of the encoded character.
     */
    private static int encodeLowerCaseChar(int ascii) {
        if (ascii <= 107) {
            // = a to k
            return ascii + 2;


        } else if ((ascii >= 108) && (ascii <= 109)) {
            // = l to m
            return ascii - 11;


        } else if ((ascii >= 110) && (ascii <= 111)) {
            // = n to o
            return ascii + 11;


        } else {
            // p to z
            return ascii - 2;
        }
    }
}
