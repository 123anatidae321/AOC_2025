use strict;
use warnings;

my $file = $ARGV[0];

die "Input file is not specified" unless($file);

open FILE, "$file" or die "Failed to open $file: $!";
my @rules;
while (<FILE>) {
    last unless (m/^(\d+)-(\d+)$/g);
    push @rules, { min => $1, max => $2 };
}

my $result = 0;

while (my $p = <FILE>) {
    foreach (@rules) {
        if ($p <= $_->{max} && $p >= $_->{min}) {
            $result++;
            last;
        }
    }
}

close FILE;

print "Result is $result\n";