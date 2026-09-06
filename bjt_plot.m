% Data points: [Vce (Volts), Ic (mA)]
data = [
0.05, 0.00
0.15, 0.70
0.30, 1.80
0.50, 2.80
0.75, 3.60
1.00, 4.10
1.25, 4.30
1.50, 4.40
2.00, 4.45
2.50, 4.52
3.00, 4.58
3.50, 4.65
4.00, 4.70
4.30, 4.75
];

% Separate columns into Vce and Ic
Vce = data(:, 1);
Ic  = data(:, 2);

% Create and format the plot
figure;
plot(Vce, Ic, 'b.-', 'LineWidth', 1.8, 'MarkerSize', 10);
hold on;
yline(4.30, 'r--', 'I_{ref} = 4.30 mA', 'LineWidth', 1.2);

title('BJT Current Mirror Output Characteristic (I_C vs V_{CE})');
xlabel('Collector-Emitter Voltage V_{CE} (V)');
ylabel('Collector Current I_C (mA)');
grid on;
xlim([0 5]);
ylim([0 6]);

% Save high-resolution PNG file
exportgraphics(gcf, 'matlab_bjt_curve.png', 'Resolution', 300);
