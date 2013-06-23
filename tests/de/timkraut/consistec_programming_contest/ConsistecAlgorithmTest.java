package de.timkraut.consistec_programming_contest;

import org.junit.runner.*;
import org.junit.runners.*;
import org.junit.Test;
import static junit.framework.Assert.*;

/**
 * Tests the ConsistecAlgorithm class.
 *
 * @author Tim Kraut
 */
@RunWith(JUnit4.class)
public class ConsistecAlgorithmTest {

    /**
     * Encode the character A.
     */
    @Test
    public void encodeA() throws Exception {
        assertEquals("M", ConsistecAlgorithm.encode("A"));
    }

    /**
     * Encode any character between B and M.
     */
    @Test
    public void encodeBToM() throws Exception {
        assertEquals("A", ConsistecAlgorithm.encode("B"));
    }

    /**
     * Encode any character between N and Y.
     */
    @Test
    public void encodeNToY() throws Exception {
        assertEquals("O", ConsistecAlgorithm.encode("N"));
    }

    /**
     * Encode the character Z.
     */
    @Test
    public void encodeZ() throws Exception {
        assertEquals("N", ConsistecAlgorithm.encode("Z"));
    }

    /**
     * Encode any character between a and k.
     */
    @Test
    public void encodeaTok() throws Exception {
        assertEquals("c", ConsistecAlgorithm.encode("a"));
    }

    /**
     * Encode the character l.
     */
    @Test
    public void encodel() throws Exception {
        assertEquals("a", ConsistecAlgorithm.encode("l"));
    }

    /**
     * Encode the character m.
     */
    @Test
    public void encodem() throws Exception {
        assertEquals("b", ConsistecAlgorithm.encode("m"));
    }

    /**
     * Encode any character between p and z.
     */
    @Test
    public void encodepToZ() throws Exception {
        assertEquals("n", ConsistecAlgorithm.encode("p"));
    }
}
