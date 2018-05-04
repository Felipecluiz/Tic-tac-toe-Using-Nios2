library ieee;
use ieee.std_logic_1164.all;

entity SpocTest is
port (
			CLOCK50: in  std_logic;
			RESET: in  std_logic;
			LEDR: out  std_logic_vector (8 downto 0)
		);
end SpocTest;

architecture behave of SpocTest is

    component DevTutorial is
        port (
                              
				clk_clk    								  : in  std_logic                    := 'X'; -- clk
            reset_reset_n                      : in  std_logic                    := 'X'; -- reset_n
            led_pio_external_connection_export : out std_logic_vector(8 downto 0)         -- export
        );
    end component DevTutorial;
begin
    u0 : DevTutorial
        port map (
            clk_clk                            => CLOCK50,          --                         clk.clk
            reset_reset_n                      => RESET,    --                       reset.reset_n
            led_pio_external_connection_export => LEDR  -- led_pio_external_connection.export
        );
end behave;
--SpocTest