use std::iter;

impl Solution {
    pub fn process_str(s: String) -> String {
        let mut result = String::new();
        
        for c in s.chars() {
            match c {
                '*' => { result.pop(); }
                '#' => { result.extend_from_within(0..); }
                '%' => { result = result.chars().rev().collect(); }
                _ => { result.push(c); }
            }
        }

        result
    }
}