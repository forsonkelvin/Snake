#include "geometry.hxx"

Geometry::Geometry() noexcept
        : thorns_num    {6}
        , fruits_num    {6}
        , shots_num     {100}
        , shot_radius   {10}
        , snake_length  {0}
        , snake_radius  {10}
        , top_margin    {50}
        , side_margin   {50}
        , scene_dims    {1024,768}
        , fruit_dims    {35,35}
        , thorn_dims    {35,35}
        , snake_dims    {20,20}
        , snake_vel     {2,0}
        , score         {0}
        , shot_vel      {5,0}

{};

