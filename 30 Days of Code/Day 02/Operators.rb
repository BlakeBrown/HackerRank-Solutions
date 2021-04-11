meal_cost = gets.to_f

tip_percent = gets.chomp.to_f

tax_percent = gets.to_f

tip = meal_cost * tip_percent / 100
tax = meal_cost * tax_percent / 100
price = meal_cost + tip + tax
puts "#{price.round}\n"
