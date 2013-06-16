package de.timkraut.consistec_programming_contest;

import static de.timkraut.consistec_programming_contest.ObjectNullException.*;

/**
 * Encode characters according to the algorithm refactored from the sample files.
 *
 * @author Tim Kraut
 */
public final class ConsistecAlgorithm {
    // Other constants
    private static final int VALUE_INITIAL = 0;
    private static final int EOS           = -1; // End of string

    /**
     * Prevent instantiating.
     */
    private ConsistecAlgorithm() {}

    /**
     * Encodes a single character according to the following algorithm: <h1>Upper case characters</h1>
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
     * @param character Character to encode.
     *
     * @return Encoded character.
     *
     * @throws ObjectNullException Given character is null.
     */
    public static int encodeChar(char character) throws ObjectNullException {
        checkNotNull(character);

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
