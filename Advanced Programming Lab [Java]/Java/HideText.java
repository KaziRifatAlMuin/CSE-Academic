public class HideText {
    // Method to encode a message
    public static String encodeMessage(String message) {
        StringBuilder encoded = new StringBuilder();
        for (char c : message.toCharArray()) {
            // Get binary representation of each character
            String binary = String.format("%8s", Integer.toBinaryString(c)).replace(' ', '0');
            
            // Replace 0 with space and 1 with tab
            for (char b : binary.toCharArray()) {
                if (b == '0') {
                    encoded.append(' '); // space for 0
                } else {
                    encoded.append('\t'); // tab for 1
                }
            }
        }
        return encoded.toString();
    }

    // Method to decode the encoded message
    public static String decodeMessage(String encodedMessage) {
        StringBuilder decoded = new StringBuilder();
        for (int i = 0; i < encodedMessage.length(); i += 8) {
            StringBuilder binary = new StringBuilder();
            // Read 8 characters (either space or tab) at a time
            for (int j = 0; j < 8; j++) {
                char c = encodedMessage.charAt(i + j);
                if (c == ' ') {
                    binary.append('0');
                } else if (c == '\t') {
                    binary.append('1');
                }
            }
            // Convert binary string back to character and append to result
            int charCode = Integer.parseInt(binary.toString(), 2);
            decoded.append((char) charCode);
        }
        return decoded.toString();
    }

    public static void main(String[] args) {
        // Test message
        String message = "I love Java!";
        
        // Encoding the message
        String encoded = encodeMessage(message);
        System.out.println("Encoded message (spaces and tabs):");
        System.out.println(encoded);

        // Decoding the message
        String decoded = decodeMessage(encoded);
        System.out.println("Decoded message:");
        System.out.println(decoded);
    }
}
