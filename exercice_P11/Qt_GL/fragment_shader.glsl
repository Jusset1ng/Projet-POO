varying vec4 ma_couleur; // Maintenant, c'est un vec4 avec la composante alpha pour l'opacité

void main()
{
  gl_FragColor = ma_couleur; // L'opacité est maintenant incluse dans ma_couleur
}
