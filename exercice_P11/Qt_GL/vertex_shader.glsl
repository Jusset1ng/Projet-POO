attribute vec3 sommet;
attribute vec4 couleur; // Maintenant un vec4 pour inclure l'opacité

uniform mat4 projection;
uniform mat4 vue_modele;

varying vec4 ma_couleur; // Maintenant un vec4 pour inclure l'opacité

void main()
{
  gl_Position = projection * vue_modele * vec4(sommet, 1.0);
  ma_couleur = couleur; // Transmettre la couleur (y compris l'opacité) au shader de fragment
}
