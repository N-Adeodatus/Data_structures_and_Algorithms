/*
DAME GAME:
Step1, discover variables by physically implementing a small example:
    1 (start): 
        - have two players (player1 & player2)
        - bring a board (board_structure)
        - bring two types of tiles for each player (tile_type_x & tile_type_y)
        - have have 20 tiles for each player (pl1_num_tiles & pl2_num_tiles )

    2 (place the tile on the board):
        - I need to know whose player I'm placing the tiles for.(till_type_x & tile_type_y)
        - know which end of the board do I need to start placing tiles (placing_init_position)
        - know where to find the tile (tyles_for_x & tyles_for_y)
        - I need to know where to put the tile on the board (tile_destination)
        - I need to know when the tiles of a player are done placing (done_placing)
        - I need to know when both tile types are done being placed (done_placing_for_both_players)

    3 (playing):
        - I need to know whether the tile I moved the tile is an empty position(is_destination_empty)
        - I need to know whether the tile I moved the tile is containing another tile of the same player(is_dest_holding_same)
        - I need to know whether the tile I moved the tile is containing an opponent's tile with another opponent's tile next to that() 

*/


