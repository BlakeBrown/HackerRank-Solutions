void solve(double meal_cost, int tip_percent, int tax_percent) {
        // Get the Tax
        double tax = (meal_cost * tax_percent) / 100;
        // Get the Tip
        double tip = (meal_cost * tip_percent/100);
        // Total Cost
        double totalCost = meal_cost + tax + tip;
        // Round the total cost and output to console
        cout<<round(totalCost)<<endl;
}
