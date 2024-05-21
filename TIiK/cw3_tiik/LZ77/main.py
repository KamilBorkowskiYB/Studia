def lz77_compress(input_str, window_size):
    compressed_data = []
    window = ''
    while input_str:
        match = ''
        match_index = 0

        # Find the longest repeated occurrence of input that begins in the window
        for i in range(1, min(len(input_str), window_size) + 1):
            substr = input_str[:i]
            last_occurrence = window.rfind(substr)
            if last_occurrence != -1:
                match = substr
                match_index = len(window) - last_occurrence
            else:
                break

        if match:
            d = match_index
            l = len(match)
            c = input_str[l] if l < len(input_str) else ''
        else:
            d = 0
            l = 0
            c = input_str[0]

        # Output (d, l, c)
        compressed_data.append((d, l, c))

        # Discard l + 1 chars from front of window
        window = window[l + 1:]

        # Pop l + 1 chars from front of input
        input_str = input_str[l + 1:]

        # Append s to back of window
        window += input_str[:l + 1]

    return compressed_data


# Example usage:
input_str = "DEEEAADDEEEEDEEEDDAAAAAABA"
window_size = 4
compressed_data = lz77_compress(input_str, window_size)
print(compressed_data)
