#ifndef UTILS_HPP
#define UTILS_HPP

namespace Utils {
#include <raylib.h>

  typedef Vector2 Position;

  typedef Position Size;

  Size screenSize = {800, 600};

  // void DrawTexturePoly(Texture2D texture, Vector2 center, Vector2 *points, Vector2 *texcoords, int pointCount, Color tint)
  // {
  //   rlSetTexture(texture.id);

  //   // Texturing is only supported on RL_QUADS
  //   rlBegin(RL_QUADS);
    
  //   rlColor4ub(tint.r, tint.g, tint.b, tint.a);

  //   for (int i = 0; i < pointCount - 1; i++)
  //   {
  //     rlTexCoord2f(0.5f, 0.5f);
  //     rlVertex2f(center.x, center.y);

  //     rlTexCoord2f(texcoords[i].x, texcoords[i].y);
  //     rlVertex2f(points[i].x + center.x, points[i].y + center.y);

  //     rlTexCoord2f(texcoords[i + 1].x, texcoords[i + 1].y);
  //     rlVertex2f(points[i + 1].x + center.x, points[i + 1].y + center.y);

  //     rlTexCoord2f(texcoords[i + 1].x, texcoords[i + 1].y);
  //     rlVertex2f(points[i + 1].x + center.x, points[i + 1].y + center.y);
  //   }
  //   rlEnd();

  //   rlSetTexture(0);
  // }
}

#endif