const std = @import("std");

fn factorial(i: i64) i64 {
    if (i > 0) {
        return i * factorial(i - 1);
    } else {
        return 1;
    }
}

fn combination(n: i64, r: i64) i64 {
    const numerator: i64 = factorial(n);
    const denom_1: i64 = factorial(r);
    const denom_2: i64 = factorial(n - r);

    return @divTrunc(numerator, denom_1 * denom_2);
}

fn pascal_triangle(n: i64, r: i64) i64 {
    if (r == 0) {
        return 1;
    } else if (n == r) {
        return 1;
    }
    return pascal_triangle(n - 1, r - 1) + pascal_triangle(n - 1, r);
}

pub fn main(init: std.process.Init) void {
    _ = init;

    const i: i64 = pascal_triangle(4, 2);
    std.debug.print("{}\n", .{i});

    return;
}
