bool sonIguales(const char *cadena1, const char *cadena2) {
    while (*cadena1 && *cadena2) {
        if (*cadena1 != *cadena2) {
            return false;
        }
        cadena1++;
        cadena2++;
    }
    return (*cadena1 == '\0' && *cadena2 == '\0');
}
